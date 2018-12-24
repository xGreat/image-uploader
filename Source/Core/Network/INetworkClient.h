/*

Image Uploader -  free application for uploading images/files to the Internet

Copyright 2007-2018 Sergey Svistunov (zenden2k@yandex.ru)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

#ifndef SRC_CORE_NETWORK_INETWORK_CLIENT_H_
#define SRC_CORE_NETWORK_INETWORK_CLIENT_H_

//
// NetworkClient interface
//
#include <string>
#include <memory>
#include "Core/Utils/CoreTypes.h"
#include "Core/3rdpart/fastdelegate.h"

typedef void CURL;
class CurlShare;

class INetworkClient {
    public:
        virtual ~INetworkClient() {}
        /*! @cond PRIVATE */
        enum ActionType {
            atNone = 0, atPost, atUpload, atGet
        };

        typedef fastdelegate::FastDelegate5<INetworkClient*, double, double, double, double, int> ProgressCallback;

        class ProxyProvider {
        public:
            virtual bool provideProxyForUrl(INetworkClient* client, const std::string& url) = 0;
            virtual ~ProxyProvider(){};
        };

        class Logger {
        public:
            virtual void logNetworkError(bool error, const std::string & msg) = 0;
            virtual ~Logger(){}
        };

        virtual void addQueryParam(const std::string& name, const std::string& value){}
        virtual void addQueryParamFile(const std::string& name, const std::string& fileName, const std::string& displayName = "", const std::string& contentType = ""){};
        virtual void addQueryHeader(const std::string& name, const std::string& value) {};
        virtual void setUrl(const std::string& url){};
        virtual bool doPost(const std::string& data = "") { return false; }
        virtual bool doUploadMultipartData(){ return false; }
        virtual bool doUpload(const std::string& fileName, const std::string &data) { return false; }
        virtual bool doGet(const std::string &url = ""){ return false; }
        virtual const std::string responseBody() { return std::string(); };
        virtual int responseCode(){ return 0; }
        virtual const std::string errorString(){ return std::string(); }
        virtual void setUserAgent(const std::string& userAgentStr) {}
        virtual const std::string responseHeaderText() { return std::string(); }
        virtual const std::string responseHeaderByName(const std::string& name){ return std::string(); }
        virtual std::string responseHeaderByIndex(int index, std::string& name){ return std::string(); }
        virtual int responseHeaderCount(){ return 0; }
        virtual const std::string getCurlResultString(){ return std::string(); }
        virtual void setCurlOption(int option, const std::string &value){}
        virtual void setCurlOptionInt(int option, long value){}
        virtual const std::string getCurlInfoString(int option){ return std::string(); }
        virtual int getCurlInfoInt(int option){ return 0; };
        virtual double getCurlInfoDouble(int option){ return 0.0; }
        virtual void setMethod(const std::string &str){};
        virtual void setProxy(const std::string &host, int port = 0, int type = 0){}
        virtual void setProxyUserPassword(const std::string &username, const std::string& password){}
        virtual void clearProxy(){};
        virtual void setReferer(const std::string &str){}
        virtual void setOutputFile(const std::string &str) {}
        virtual void setChunkOffset(double offset) {}
        virtual void setChunkSize(double size){}
        virtual int getCurlResult(){ return 0; /* CURLE_OK */ }
        virtual CURL* getCurlHandle() { return nullptr;  }
        virtual void setCurlShare(CurlShare* share) {}
        virtual void setTimeout(uint32_t timeout){}
        virtual void setConnectionTimeout(uint32_t connection_timeout){}
        virtual void enableResponseCodeChecking(bool enable) {}
        virtual void setErrorLogId(const std::string &str){}
        virtual void setProgressCallback(const ProgressCallback& func){}
        virtual void setTreatErrorsAsWarnings(bool treat){}
        virtual void setUploadBufferSize(int size){}
        virtual void setProxyProvider(std::shared_ptr<ProxyProvider> provider){}
        virtual void setLogger(Logger* logger){}
        virtual const std::string urlEncode(const std::string& str){ return std::string(); }
        virtual const std::string urlDecode(const std::string& str){ return std::string(); }
};

class INetworkClientFactory {
public:
    virtual std::unique_ptr<INetworkClient> create() = 0;
    virtual ~INetworkClientFactory() {}
};

#endif