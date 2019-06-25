#ifndef IMAGEEDITOR_MOVABLEELEMENTS_H
#define IMAGEEDITOR_MOVABLEELEMENTS_H

#include "3rdpart/GdiplusH.h"
#include "DrawingElement.h"
#include "MovableElement.h"

namespace ImageEditor {
class InputBox;
class Line: public MovableElement {
    public:
        Line(Canvas* canvas,int startX, int startY, int endX,int endY);
        void render(Painter* gr) override;
        void setEndPoint(POINT endPoint) override;
        void getAffectedSegments(AffectedSegments* segments) override;
        void createGrips() override;
        bool isItemAtPos(int x, int y) override;
        ElementType getType() const override;
};

class TextElement: public MovableElement{
    public:
        TextElement( Canvas* canvas, InputBox* inputBox, int startX, int startY, int endX,int endY );
        ~TextElement();
        void render(Painter* gr) override;
        void getAffectedSegments(AffectedSegments* segments) override;
        void resize(int width, int height) override;
        void setInputBox(InputBox* inputBox);
        void setFont(LOGFONT font,  DWORD changeMask);
        LOGFONT getFont();
        InputBox* getInputBox() const;
        ElementType getType() const override;
        void setSelected(bool selected) override;
        void beginEdit();
        void endEdit(bool saveToHist);
        void setRawText(const std::string& rawText);
        void setColor(Gdiplus::Color color) override;
        bool isEmpty() const override;
protected:
    InputBox *inputBox_;
    LOGFONT font_;
    bool isEditing_;
    bool firstEdit_;
    std::string originalRawText_;
    void onTextChanged(TCHAR *text);
    void onEditCanceled();
    void onEditFinished();
    void onControlResized(int w, int h);
    void setTextColor();
    void onSelectionChanged(int min, int max, LOGFONT font);
    void saveToHistory();
};

class Crop: public MovableElement {
public:
    Crop(Canvas* canvas, int startX, int startY, int endX,int endY);
    void render(Painter* gr) override;
    void getAffectedSegments(AffectedSegments* segments) override;
    ElementType getType() const override;
    void setPos(int  x, int y) override;
    bool move(int  offsetX, int offsetY) override;
    void resize(int width, int height) override;
};

class CropOverlay: public MovableElement {
public:
    CropOverlay(Canvas* canvas, int startX, int startY, int endX,int endY);
    void render(Painter* gr) override;
};

class BlurringRectangle: public MovableElement {
public:
    BlurringRectangle(Canvas* canvas, float blurRadius, int startX, int startY, int endX,int endY);
    ~BlurringRectangle();
    void setBlurRadius(float radius);
    float getBlurRadius() const;
    void render(Painter* gr) override;
    ElementType getType() const override;
protected:
    float blurRadius_;

};

class Rectangle: public MovableElement {
public:
    Rectangle(Canvas* canvas, int startX, int startY, int endX,int endY,bool filled = false );
    void render(Painter* gr) override;
    void getAffectedSegments(AffectedSegments* segments) override;
    bool isItemAtPos(int x, int y) override;
    RECT getPaintBoundingRect() override;

    ElementType getType() const override;

protected:
    bool filled_;

};

class FilledRectangle: public Rectangle {
public:
    FilledRectangle(Canvas* canvas, int startX, int startY, int endX,int endY );
    ElementType getType() const override;
};

class RoundedRectangle: public Rectangle {
public:
    RoundedRectangle(Canvas* canvas, int startX, int startY, int endX,int endY,bool filled = false );
    void render(Painter* gr) override;
    ElementType getType() const override;
};

class FilledRoundedRectangle: public RoundedRectangle {
public:
    FilledRoundedRectangle(Canvas* canvas, int startX, int startY, int endX,int endY );
    ElementType getType() const override;
};

class Arrow: public Line {
public:
    Arrow(Canvas* canvas,int startX, int startY, int endX,int endY);
    void render(Painter* gr) override;
    RECT getPaintBoundingRect() override;
    ElementType getType() const override;
};

class Ellipse: public MovableElement {
public:
    Ellipse(Canvas* canvas, bool filled = false );
    void render(Painter* gr) override;
    bool isItemAtPos(int x, int y) override;
    ElementType getType() const override;
    RECT getPaintBoundingRect() override;
protected:
    bool filled_;
    bool ContainsPoint(Gdiplus::Rect ellipse, Gdiplus::Point location);
    void createGrips() override;
};

class FilledEllipse: public Ellipse {
public:
    FilledEllipse(Canvas* canvas );
    ElementType getType() const override;
};

class Selection: public MovableElement {
public:
    Selection(Canvas* canvas, int startX, int startY, int endX,int endY);
    void render(Painter* gr) override;
    ElementType getType() const override;
    void createGrips() override;
};

class StepNumber : public MovableElement {
public:
    StepNumber(Canvas* canvas, int startX, int startY, int endX, int endY, int number, int fontSize);
    void setFontSize(int size);
    void render(Painter* gr) override;
    RECT getPaintBoundingRect() override;
    void setNumber(int number);
    bool isResizable() const override;

    ElementType getType() const override;
protected:
    int number_;
    int fontSize_;
    int recalcRadius();
};

}

#endif