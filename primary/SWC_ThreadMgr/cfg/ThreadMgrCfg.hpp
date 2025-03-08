/**
 * @brief Thread configuration
 * Make sure the number of threads matches the defined threads
 */
extern "C"
{
    #define THREAD_MGR_CFG_THREAD_LIST                  \
                                    primary_thread,     \
                                    secondary_thread,   \
                                    auxiliary_thread,   \
                                    diagnostic_thread
                                    
    #define THREAD_MGR_CFG_NUM_THREADS 4

}
