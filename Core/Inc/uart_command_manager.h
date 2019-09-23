#include "templates.h"
#include "types.h"
#include "command_handler.h"

class UARTCommandManager {  
    static const size_t CMD_BUFFER_SIZE = 80;

public:
    void onData(const char *pData, size_t size);
    UARTCommandManager(ICmdProcessor **proc, size_t count);

protected:
    void onCommand();

private: 
    char            _cmd_buffer[CMD_BUFFER_SIZE];
    size_t          _cmd_buffer_size = 0; 
    ICmdProcessor  **_proc;
    size_t          _proc_count; 
};