# Requirements

```c
#include <pthread.h>
```

compile with -pthread flag
<br></br>

# Available funnctions

### ------------------------ Pthread_create ------------------------ 
```c
int pthread_create(pthread_t *restrict thread,
                        const pthread_attr_t *restrict attr,
                        void *(*start_routine)(void *),
                        void *restrict arg);
```
- [Link](https://man7.org/linux/man-pages/man3/pthread_create.3.html) for manual
- [Link](https://code-vault.net/course/6q6s9eerd0:1609007479575/lesson/18ec1942c2da46840693efe9b51d86a8) for Codevault's video
- [Link](https://www.geeksforgeeks.org/thread-in-operating-system/) for GeekForGeeks

<br>

### ---------------------- pthread_mutex_init ----------------------

```c
 int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);

// In short
int pthread_mutex_init(pthread_mutex_t *mutex, 
                        pthread_mutexattr_t *attr);
```
- [Link](https://man7.org/linux/man-pages/man3/pthread_mutex_init.3p.html) for manual
- [Link](https://code-vault.net/course/6q6s9eerd0:1609007479575/lesson/18ec1942c2da46840693efe9b51eabf6) for Codevault's video

<br>

### pthread_lock

```c
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```
- [Link](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html) for manual