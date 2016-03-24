#include <stdlib.h>
#include <unistd.h>
#include "VG/openvg.h"
#include "VG/vgu.h"
#include <fontinfo.h>
#include <shapes.h>

int width, height;
int logo_w = 737, logo_h = 720;
char logo_path[50] = "/home/pi/ariss/graphic/ariss_logo.jpg";

void displayLogoConnecting(void) {
    Start(width, height);                   // Start the picture
    Background(0, 0, 0);                    // Black background

    Image((width / 2)-(logo_w / 2), (3 * height / 5) - (logo_h / 2), logo_w, logo_h, logo_path);

    Fill(255, 255, 255, 1);                 // White text
    TextMid(width / 2, 3* height / 20, "Connecting..", SansTypeface, width / 30);  // Greetings
    End();
}
void displayLogo(void) {
    Start(width, height);                   // Start the picture
    Background(0, 0, 0);                    // Black background

    Image((width / 2)-(logo_w / 2), (3 * height / 5) - (logo_h / 2), logo_w, logo_h, logo_path);

    End();
}


int main() {
    init(&width, &height);                  // Graphics initialization
    
    while(1)
    {
        if ( system("ping -c 1 -W 3 10.155.0.1 > /dev/null") == 0)
        {
            displayLogo();
        }
        else
        {
            displayLogoConnecting();
        }
        sleep(1);
    }
    
    finish();                               // Graphics cleanup
    exit(0);
}
