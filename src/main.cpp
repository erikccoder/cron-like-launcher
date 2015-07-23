#include "ofMain.h"
#include "ofApp.h"
#include "ofAppNoWindow.h"


//========================================================================
int main(int argc, char *argv[])
{
    ofAppNoWindow window;
    ofSetupOpenGL( & window, 1024, 768, OF_WINDOW);
    ofRunApp(new ofApp(argc, argv));
    return 0;
}
