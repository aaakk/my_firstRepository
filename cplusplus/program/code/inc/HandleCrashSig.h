#pragma once

#include <signal.h>
#include <iostream>
#include <execinfo.h>

void crashDump(int sig)
{
    std::cout << "Abnormal exit!" << std::endl;
    std::cout << "Program crash by sig [" << sig << "]" << std::endl;

    const int len = 1024;
    void *func[len];
    
    auto size = backtrace(func, len);
    char** funs = backtrace_symbols(func, size);
    for(int i = 0; i < size; i++)
    {
        fprintf(stderr, "[%d] %s \n", i, funs[i]);
    }
    free(funs);

    exit(-1);
}

#define SIG_DUMP(SIG_NO) signal(SIG_NO, &crashDump);

void HandleCrashSig()
{
    SIG_DUMP(SIGSEGV);
    SIG_DUMP(SIGFPE);
    SIG_DUMP(SIGINT);
    SIG_DUMP(SIGILL);
    SIG_DUMP(SIGABRT);
}