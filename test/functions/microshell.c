/*  Execute the program */
/*  envp - all the environment variables,*/
int exec(char **argv, char **envp, int i) 
{
    int fd[2];
    int status;
    int has_pipe = argv[i] && !strcmp(argv[i], "|");    // Check if string argv[i] exist, and if it contains the pipe

    /*  1. check if pipe exist  */
    /*  2. if exist, pipe()     */
    if (has_pipe && pipe(fd) == -1)                     
        return err("error: fatal\n");

    /*  Create a new process    */
    int pid = fork();
    if (!pid) 
    {
        /*  Child process       */
        argv[i] = 0;
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return err("error: fatal\n");
        execve(*argv, argv, envp);
        return err("error: cannot execute "), err(*argv), err("\n");
    }

    waitpid(pid, &status, 0);
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        return err("error: fatal\n");
    return WIFEXITED(status) && WEXITSTATUS(status);
}