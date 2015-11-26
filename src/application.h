#ifndef APPLICATION_H
#define APPLICATION_H

class Application
{
public:
    static Application& getInstance();
    int run();
private:
    // Utility methods.
    int parseCmdLine(int argc, char* argv[]);
    void printOutput();

    // Private constructor/Destructor required by Singleton pattern.
    Application() {};
    ~Application() {};

    // Avoid copy constructor.
    Application(const Application&);
    Application& operator=(const Application&);
}
#endif
