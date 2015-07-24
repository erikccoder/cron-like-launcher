# cronExpressionLike Launcher

cron expressions liked syntax / expression launcher.
paser is based on [crontab-parser](https://github.com/ben-crowhurst/crontab-parser)

CRON Expressions
================

A CRON expression is a string representing the schedule for a particular command to execute.  The parts of a CRON schedule are as follows:

    *    *    *    *    *    
    -    -    -    -    -    
    |    |    |    |    |    
    |    |    |    |    +----- day of week (0 - 7) (Sunday=0 or 7)
    |    |    |    +---------- month (1 - 12)
    |    |    +--------------- day of month (1 - 31)
    |    +-------------------- hour (0 - 23)
    +------------------------- min (0 - 59)


## Usage:
* ./cronLikeLauncher [command] [cron expression]
 
## Example:
* ./cronLikeLauncher "echo 123" "* * * * 1" (echo "123" if it's Monday on your system)


