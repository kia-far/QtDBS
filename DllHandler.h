#ifndef DLLHANDLER_H
#define DLLHANDLER_H

#include <QLibrary>
#include <QString>

class DllHandler {
public:
    static bool loadDll(const QString& dllPath);
    static void unloadDll();

    static int openPort( int i);
    static int closePort();

    static int setLabelHeight(unsigned int height, unsigned int gap);
    static int setLabelWidth(unsigned int width);
    static int drawQRCode(int x, int y, const QString& content);
    static int drawBarCode(int x, int y, const QString& content);
    static int printLabel(int copies, int pause);
    static int setPrintSpeed(unsigned int speed);
    static int clearbuffer();
    static int setDirection(char let);
    static int setFont(int x,int y,int direc,int font,int hori,int vert,char color,const char* text);

private:
    static QLibrary library;

    typedef int (*OpenPortFunc)(int);
    typedef int (*ClosePortFunc)();
    typedef  int (*SetLabelHeightFunc)(unsigned int,unsigned int);
    typedef  int (*SetLabelWidthFunc)(unsigned int);
    typedef int (*DrawQRFunc)(int, int,int,int,int,int,int,int,int, const char*);
    typedef int (*DrawBarFunc)(int, int,int,const char*,int,int,int,const char,const char*);
    typedef int (*PrintLabelFunc)(int, int);
    typedef int (*SetPrinterSpeed)(unsigned int);
    typedef int(*ClearBuffer)();
    typedef int (*SetDirection)(char let);
    typedef int (*SetFontName)(int,int,int,int,int,int,char font,const char*);

    static OpenPortFunc OpenPort;
    static ClosePortFunc ClosePort;
    static SetLabelHeightFunc PTK_SetLabelHeight;
    static SetLabelWidthFunc PTK_SetLabelWidth;
    static DrawQRFunc PTK_DrawBarcode2D_QR;
    static DrawBarFunc PTK_DrawBarcode;
    static PrintLabelFunc PTK_PrintLabel;
    static SetPrinterSpeed PTK_SetPrintSpeed;
    static ClearBuffer PTK_ClearBuffer;
    static SetDirection PTK_SetDirection;
    static SetFontName PTK_SetBarCodeFontName;

};

#endif // DLLHANDLER_H
