#include "DllHandler.h"
#include <QDebug>
#include <QString>
// #include "winnt.h"

QLibrary DllHandler::library;
DllHandler::OpenPortFunc DllHandler::OpenPort = nullptr;
DllHandler::ClosePortFunc DllHandler::ClosePort = nullptr;
DllHandler::SetLabelHeightFunc DllHandler::PTK_SetLabelHeight = nullptr;
DllHandler::SetLabelWidthFunc DllHandler::PTK_SetLabelWidth = nullptr;
DllHandler::DrawQRFunc DllHandler::PTK_DrawBarcode2D_QR = nullptr;
DllHandler::DrawBarFunc DllHandler::PTK_DrawBarcode = nullptr;
DllHandler::PrintLabelFunc DllHandler::PTK_PrintLabel = nullptr;
DllHandler::SetPrinterSpeed DllHandler::PTK_SetPrintSpeed = nullptr;
DllHandler::ClearBuffer DllHandler::PTK_ClearBuffer = nullptr;
DllHandler::SetDirection DllHandler::PTK_SetDirection = nullptr;
DllHandler::SetFontName DllHandler:: PTK_SetBarCodeFontName = nullptr;

bool DllHandler::loadDll(const QString& dllPath) {
    library.setFileName(dllPath);
    if (!library.load()) {
        qWarning() << "Failed to load DLL:" << library.errorString();
        return false;
    }

    OpenPort = (OpenPortFunc)library.resolve("OpenUSBPort");
    ClosePort = (ClosePortFunc)library.resolve("CloseUSBPort");
    PTK_SetLabelHeight = (SetLabelHeightFunc)library.resolve("PTK_SetLabelHeight");
    PTK_SetLabelWidth = (SetLabelWidthFunc)library.resolve("PTK_SetLabelWidth");
    PTK_DrawBarcode2D_QR = (DrawQRFunc)library.resolve("PTK_DrawBar2D_QR");
    PTK_DrawBarcode = (DrawBarFunc)library.resolve("PTK_DrawBarcode");
    PTK_PrintLabel = (PrintLabelFunc)library.resolve("PTK_PrintLabel");
    PTK_SetPrintSpeed = (SetPrinterSpeed)library.resolve("PTK_SetPrintSpeed");
    PTK_ClearBuffer = (ClearBuffer)library.resolve("PTK_ClearBuffer");
    PTK_SetDirection = (SetDirection)library.resolve("PTK_SetDirection");
    PTK_SetBarCodeFontName = (SetFontName)library.resolve("PTK_DrawText");

    // if (!OpenPort || !ClosePort || !PTK_SetLabelHeight || !PTK_SetLabelWidth || !PTK_DrawBarcode2D_QR || !PTK_PrintLabel) {
    //     qWarning() << "Failed to resolve one or more functions!";
    //     unloadDll();
    //     return false;
    // }

    return true;
}

void DllHandler::unloadDll() {
    if (library.isLoaded()) {
        library.unload();
    }
}

int DllHandler::openPort( int i) {

    return OpenPort(i);
}

int DllHandler::closePort() {
    return ClosePort();
}

int DllHandler::setLabelHeight(unsigned int height,unsigned int gap) {
    return PTK_SetLabelHeight(height, gap);
}

int DllHandler::setLabelWidth(unsigned int width) {
    return PTK_SetLabelWidth(width);
}

int DllHandler::drawQRCode(int x, int y, const QString& content) {
    QString newContent = DllHandler::countChars(content);
    // QString myString = newContent;
    // LPCSTR
    // QString::utf16(newContent.toUtf8().constData())
    return PTK_DrawBarcode2D_QR(x, y, 200 , 175, 0, 2, 1, 0, 8,content.toUtf8().constData());
}
int DllHandler::drawBarCode(int x, int y, const QString& content) {
    QString a = "1";
    return PTK_DrawBarcode(x, y, 0 , a.toUtf8() , 1, 1,60, 'N',content.toUtf8().constData());
}

int DllHandler::printLabel(int copies, int pause) {
    return PTK_PrintLabel(copies, pause);
}
int DllHandler::setPrintSpeed(unsigned int speed){
    return PTK_SetPrintSpeed(speed);
}
int DllHandler::clearbuffer(){
    return PTK_ClearBuffer();
}
int DllHandler::setDirection(char let){
    return PTK_SetDirection (let);

}
int DllHandler::setFont(int x,int y,int direc,int font,int hori,int vert,char color,const char* text){
    return PTK_SetBarCodeFontName( x, y, direc, font, hori, vert, color, text);
}
QString DllHandler::countChars(QString input){
    int englishCount = 0;
    int persianCount = 0;
    int symbolCount = 0;
    QString text=input;
    // Iterate through each character in the input
    for (const QChar& c : input) {
        if (c.isLetter()) {
            // Check if the character is an English letter (a-zA-Z)
            if (c.unicode() >= 'A' && c.unicode() <= 'Z' ||
                c.unicode() >= 'a' && c.unicode() <= 'z') {
                ++englishCount;
            }
            // Check if the character is a Persian letter (Unicode range)
            else if (c.unicode() >= 0x0600 && c.unicode() <= 0x06FF) {
                ++persianCount;
            }
        }
        // Check if the character is a symbol
        else if (QString("[]!@#$%^&*()-=_+{}|:;\"'<>,.?/\\`~").contains(c)) {
            ++symbolCount;
        }
    }
    int charDeficit =400- (symbolCount+englishCount+persianCount*2);
    for(int i=0;i<charDeficit;i++){
        text.append(" ");
    }
    qDebug() << symbolCount<<englishCount<<persianCount<<charDeficit;
    return text;
}
