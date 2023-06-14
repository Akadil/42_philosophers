# 42project_philosophers
This project is about learning the basics of threading a process

# Planning period

## Main function
Very simple. Just do the parsing and  then create the threads
```c
def main:
    t_list   *t1;
    t_data   data;
    int      i;

    t1 = NULL;
    ft_parsing(argc, argv, env???);
    ft_initalization(&t1, data);
    i = 0;
    while (i < num_philo)
    {
        pthread_create(data.philo[i].id, NULL, &routine, data.philo[i]);
        i++;
    }
    ft_close_threads();
    return (0);
```
- Here I need to have error management for pthread_create()
- In ft_close_threads(), free the philos and free the mutex 

<br>
<br>

## Data structure
The data are going to be stored inside of linked list. Where void *content, points to the t_philo structure
- t_data: general game rules
- t_philo: Philo's structure
```c
typedef struct s_data
{
    int num;
    int time_die;
    int time_sleep;
    int time_eat;
    int success;

    // Ideentificator that some of them died
    int died;
}       t_data;

typedef struct  s_philo
{
    // Philo's info
    pthread_t       id;
    pthread_mutex_t mutex;
    int             fork;
    int             time_eat_started;
    int             status;
    int             round;

    // Reference to global rules
    t_data          *data;
}                   t_philo;
```
- This structure will be statically allocated 
- Each philo should have access to this data

<br>

### Parsing the data and philo initialization

```c
void    ft_parsing(int argc, char **argv)
{
    if (argc != 4 && argc != 5)
        ft_merror_exit("Wrong number");
    if (ft_isnum(argv[0]) == 0)
        ft_error("Wrorng type");
    if (num less  than 0)
        ft_error("wrong number");
    if (any of times is less than 0)
        ft_error("wrorng time");
}

void    ft_initialization(t_data *data)
{
    t_list  *philos;
    t_list  *temp;
    t_philo *philo;
    int     i;

    philos = NULL;
    
    // Initialize each of philos
    i = 0;
    while (i < data->num)
    {
        philo = (t_philo  *)malloc(sizeof(t_philo));
        philo->fork = 0;
        philo->status = 0;
        philo->times* = 0;
        philo->round = 1;
        temp = ft_lstnew(philo, i + 1);
        ft_lstadd_back(*philos, temp);
        i++;
    }

    // Create a mutex for each of them
    i = 0;
    temp = philos;
    while (i < num)
    {
        pthread_mutex_init(temp->content->mutex, NULL);
        temp = temp->next;
        i++;
    }

    // Make a circle for them
    philos->prev = temp;
    temp->next = philos;
}
```
- Handle error in malloc
- Handle error in mutex initialization 

<br>

### Philosopher's routine function

```c
void    *routine(t_list *philo)
{
    ft_init_the_time();
    while (1)
    {
        if (ft_take_fork(philo) != 0)
            break;
        if (ft_start_eating(philo) != 0)
            break;
        if (ft_start_sleeping(philo) != 0)
            break;
    }
}
```
- I have to consider in which place I have to put if conditions to check if other philo died

<br>

### Start doing some action. Ft_take_fork()

```python 3
def take_fork(philo) -> int:
    
    # If the philo has to wait this round, it has to sleep
    while (not your turn)
        ft_think(time_eat) # Wait other philos eating
    # In this scenario, I have to also consider that he might die while waiting. 

    # Once I am here, I can start taking my stuff
    if take_left() is fail:
        return -1
    if take_right() is fail:
        return -1

def is_my_turn(philo):
    int num

    pos_host = philo.round % philo.game.num_philo
    while (i < num_iter)
    {
        if (philo.num == pos_host)
            return True
        pos_host += 2
    }
    return False
```


```python 3
def take_left(philo):
    if (philo.fork != 0)
        ft_think(philo, philo.left)
    else
        mutex_lock(mutex)
        philo.fork += 1

def take_right(philo):
    if (philo.right.fork != 0)
        ft_think(philo, philo.right)
    else
        mutex_lock(right.mutex)
        philo.right.fork += 1
```

```python 3
def ft_think(philo, philo2) -> int:
    int time_available = 0
    int time_needed = 0

    
    # The example:
    # ----------------
    # 1. [0.10.00]    - last time I eat
    # 2. [0.14.00]    - current time
    # 3. 4ms          - Time since the last meal
    # 3. 5ms          - time to die
    time_available =    philo.game.time_die
                            - (philo.eat_started - current_time) 
    time_needed =       philo.game.time_eat
    
    # I have 2 secs remaining, but my mate will still eat for 3 sec 
    if (time_available - time_needed < 0)
        sleep(time_needed - time_available)
        die()
        return -1
    else
        print("I am thinking!!!")
        sleep(time_needed)
```

```python 3
def ft_eat():
    if (time passed)
        unlock(mutexes)
        die()
        return -1
    print("Philo is eating")
    update_time(philo.last_meal)
    sleep(time_eat)
```

```python 3
def sleep():
    if (enough time):
        sleep(time_sleep)
        print(sleep)
    else:
        sleep(till he has a time)
        die()
        return -1
```
- What if I have negative time, do I have  to die?