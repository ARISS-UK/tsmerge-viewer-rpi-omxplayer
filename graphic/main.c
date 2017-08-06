#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "VG/openvg.h"
#include "VG/vgu.h"
#include <fontinfo.h>
#include <shapes.h>

#include "ariss_logo.h"
static int logo_w = 737, logo_h = 720;

static int terminated; 

void signal_handler(int sig)
{
    if (sig == SIGINT || sig == SIGTERM)
    {
        terminated = 1;
    }
}

int main() {
    int width, height;
    char tmp_logo_filename[] = "/tmp/ariss-graphic_XXXXXX";

    terminated = 0;
    if (signal(SIGINT, signal_handler) == SIG_ERR
     || signal(SIGTERM, signal_handler) == SIG_ERR)
    {
        printf("Error setting up signal handler!\n");
        return 1;
    }

    int tmp_logo_file = mkstemp(tmp_logo_filename);
    if(tmp_logo_file < 0)
    {
        printf("Error opening temporary file for logo!\n");
        return 1;
    }
    write(tmp_logo_file, ariss_logo_jpg, ariss_logo_jpg_len);
    close(tmp_logo_file);
    
    init(&width, &height);                  // Graphics initialization
    
    Start(width, height);                   // Start the picture
    Background(0, 0, 0);                    // Black background
    Image((width / 2)-(logo_w / 2), (3 * height / 5) - (logo_h / 2), logo_w, logo_h, tmp_logo_filename);
    
    //Fill(255, 255, 255, 1);                 // White text
    //TextMid(width / 2, 3* height / 20, "Connecting..", SansTypeface, width / 30);

    End();
        
    while(!terminated) { usleep(100*1000); }
    
    finish();                               // Graphics cleanup
    unlink(tmp_logo_filename);
    
    return 0;
}
