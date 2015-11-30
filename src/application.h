#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>

class Application
{
public:
    static Application& getInstance();
    int run(double inputPrice);
    double parseCmdLine(int argc, char* argv[]);
private:
    // Utility methods.
    void printUsage();

    // Private constructor/Destructor required by Singleton pattern.
    Application() {};
    ~Application() {};

    // Avoid copy constructor.
    Application(const Application&);
    Application& operator=(const Application&);
};
#endif
