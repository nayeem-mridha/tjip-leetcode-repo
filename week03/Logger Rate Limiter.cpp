class Logger {
public:
    unordered_map<string,int> myTimes;

    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (myTimes.find(message) == myTimes.end()) {
            myTimes[message] = timestamp + 10;
            return true;
        }
        else if (timestamp >= myTimes[message]) {
            myTimes[message] = timestamp + 10;
            return true;
        }
        else {
            return false;
        } 

        return true;
    }
};



