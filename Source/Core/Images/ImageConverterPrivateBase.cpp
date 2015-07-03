﻿#include "ImageConverterPrivateBase.h"

#include <Core/Utils/CoreUtils.h>
#include <Core/3rdpart/pcreplusplus.h>
#include <Core/Utils/StringUtils.h>
#include <Core/3rdpart/parser.h>

ImageConverterPrivateBase::ImageConverterPrivateBase()
{
    generateThumb_ = false;
    thumbnailTemplate_ = 0;
    processingEnabled_ = true;
}

uint32_t ImageConverterPrivateBase::EvaluateColor(const std::string& expr)
{
    uint32_t color = 0;
    color = EvaluateExpression(expr);
    color = ((color << 8) >> 8) | ((255 - (color >> 24)) << 24);
    return color;
}

int ImageConverterPrivateBase::EvaluateExpression(const std::string& expr)
{
    std::string processedExpr = ReplaceVars(expr);
    return static_cast<int>(EvaluateSimpleExpression(processedExpr));
}

int64_t ImageConverterPrivateBase::EvaluateSimpleExpression(const std::string& expr) const
{
    TParser parser;
    int64_t res = 0;
    try
    {
        parser.Compile(expr.c_str());
        res = static_cast<int64_t>(parser.Evaluate());
    }
    catch (TError& err)
    {
        LOG(ERROR) << err.error;
    }
    return res;
}

std::string ImageConverterPrivateBase::ReplaceVars(const std::string& expr)
{
    std::string Result = expr;

    pcrepp::Pcre reg("\\$\\(([A-z0-9_]*?)\\)", "imc");
    std::string str = (expr);
    size_t pos = 0;
    while (pos < str.length())
    {
        if (reg.search(str, pos))
        {
            pos = reg.get_match_end() + 1;
            std::string vv = reg[1];
            std::string value = m_Vars[vv];

            Result = IuStringUtils::Replace(Result, std::string("$(") + vv + std::string(")"), value);
        }
        else
            break;
    }

    // Result  = IuStringUtils::Replace(Result,std::string("#"), "0x");
    {
        pcrepp::Pcre reg("\\#([0-9A-Fa-f]+)", "imc");
        std::string str = (Result);
        size_t pos = 0;
        while (pos < str.length())
        {
            if (reg.search(str, pos))
            {
                pos = reg.get_match_end() + 1;
                std::string vv = reg[1];
                unsigned int res = strtoul(vv.c_str(), 0, 16);
                std::string value = m_Vars[vv];

                Result = IuStringUtils::Replace(Result, std::string("#") + vv, IuCoreUtils::toString(res));
            }
            else
                break;
        }
    }
    return Result;
}