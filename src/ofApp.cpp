#include "ofApp.h"

using namespace std;

const int MINUTESPERHOUR = 60;
const int HOURESPERDAY   = 24;
const int MONTHSPERYEAR  = 12;
const int DAYSPERMONTH   = 31;
const int DAYSPERWEEK    =  7;


string expand( const string& expression )
{
    string result = "";
    
    if ( expression.find( "-" ) != string::npos )
    {
        vector< string > rangearray = ofSplitString( expression, "-" );
        
        int start = ofToInt( rangearray[ 0 ] );
        int stop = ofToInt( rangearray[ 1 ] );
        
        for(int index = start; index <= stop; index++ )
        {
            result.append( ofToString( index ) + "," );
        }
    }
    else
    {
        result = expression + ",";
    }
    
    return result;
}

vector< string > parse(string expression, int maximum, int minimum)
{
    vector< string > subexpressions;
    
    if ( expression.find( "," ) != string::npos )
    {
        subexpressions = ofSplitString( expression, "," );
    }
    else
    {
        subexpressions.push_back(expression);
    }
    
    string rangeitems;
    
    for (const auto& subexpression : subexpressions)
    {
        if (subexpression.find("/") != string::npos) // handle */N syntax
        {
            for (int a = 1; a <= maximum; a++)
            {
                if (a % ofToInt(subexpression.substr(subexpression.find("/")+1)) == 0)
                {
                    if(a == maximum)
                    {
                        rangeitems.append(ofToString(minimum));
                    }
                    else
                    {
                        rangeitems.append(ofToString(a));
                    }
                    
                    rangeitems.append(",");
                }
            }
        }
        else
        {
            if(subexpression == "*")
            {
                rangeitems.append(expand(ofToString(minimum) + "-" + ofToString(maximum)));
            }
            else
            {
                rangeitems.append(expand(subexpression));
            }
        }
    }
    
    return ofSplitString( rangeitems, "," );
}


//--------------------------------------------------------------
ofApp::ofApp(int argc, char *argv[])
{
    isArgsOk = argc > 1;
    
    if(isArgsOk)
        cmd = ofToString(argv[1]);
    
    condition.resize(5);
    vector<string> _conArgs;
    if(argc > 2)
    {
        _conArgs = ofSplitString(ofToString(argv[2]), " ");
    }
    
    for (int i = 0; i<condition.size(); i++)
    {
        if(i < _conArgs.size())
        {
            condition[i] = _conArgs[i];
        }
        else
        {
            condition[i] = "*";
        }
    }
    ofSetLogLevel(OF_LOG_NOTICE);
}

//--------------------------------------------------------------
void ofApp::setup()
{
    vector<string> mins  = parse(condition[0], MINUTESPERHOUR, 0);
    vector<string> hours = parse(condition[1], HOURESPERDAY, 0);
    vector<string> days  = parse(condition[2], DAYSPERMONTH, 0);
    vector<string> months = parse(condition[3], MONTHSPERYEAR, 0);
    vector<string> weekday = parse(condition[4], DAYSPERWEEK, 0);
    

    bool isMinsOk  = ofFind(mins, ofToString(ofGetMinutes())) < mins.size();
    bool isHoursOk = ofFind(hours, ofToString(ofGetHours())) < hours.size();
    bool isDaysOk  = ofFind(days, ofToString(ofGetDay())) < days.size();
    bool isMonthsOk = ofFind(months, ofToString(ofGetMonth())) < months.size();
    bool isWeekdayOk = ofFind(weekday, ofToString(ofGetWeekday())) < weekday.size();
    
    bool canRunCmd = ( isMinsOk && isHoursOk && isDaysOk && isMinsOk && isWeekdayOk );
    
    if(canRunCmd)
        ofLog() << "output: " << ofSystem(cmd);
    else
        ofLog() << "Conditions didn't match.";

    ofExit();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
