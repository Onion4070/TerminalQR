#include <iostream>
#include <qrencode.h>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    #ifdef _WIN32
    // Set console output code page to UTF-8
    std::cout << "Setting console output code page to UTF-8..." << std::endl;
    SetConsoleOutputCP(CP_UTF8);
    #endif

    // Example message
    const char* message = "Hello, World! こんにちは世界！";
    QRcode* qr = QRcode_encodeString(message, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Check if QR code generation was successful
    if (!qr) {
        std::cerr << "Failed to generate QR Code." << std::endl;
        exit(1);
    }

    std::cout << "QR Code generated successfully!" << std::endl;
    std::cout << "Version: " << qr->version << std::endl;
    std::cout << "Width: " << qr->width << std::endl;
    // Print the QR code data to the console

    // Border size arround the QR code
    const int border = 1;

    const int w = qr->width;
    unsigned char* data = qr->data;

    for (int y = -border; y < w + border; y += 2) {
        for (int x = -border; x < w + border; ++x) {

            bool bottom = false;    // ██  <- top pixel
            bool top    = false;    // ██  <- bottom pixel

            // top pixel
            if (x >= 0 && y >= 0 && x < w && y < w) 
                top = data[y * w + x] & 1;

            // bottom pixel
            if (x >= 0 && y + 1 >= 0 && x < w && y + 1 < w) 
                bottom = data[(y + 1) * w + x] & 1;

            // fix the last bottom row
            if (y + 1 >= w + border) 
                bottom = true;

            // Invert the colors;
            top = !top;
            bottom = !bottom;

            if (top && bottom)
                std::cout << "\xE2\x96\x88";  // █ in UTF-8 bytes
            else if (top && !bottom)
                std::cout << "\xE2\x96\x80";  // ▀ in UTF-8 bytes
            else if (!top && bottom)
                std::cout << "\xE2\x96\x84";  // ▄ in UTF-8 bytes
            else
                std::cout << " ";
        }
        std::cout << "\n";
    }
    // Free the allocated memory
    QRcode_free(qr);

    return 0;
}