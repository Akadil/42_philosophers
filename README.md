# 42project_philosophers
This project is about learning the basics of threading a process

# Planning period

### Main function
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

### Data structure
```c
typedef struct s_data
{
    // General game rules
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
    int             time;

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
    if take_left() is fail:
        return -1
    if take_right() is fail:
        return -1
    print("`the philo {i} took the forks")

def take_left(philo):
    if (philo.fork != 0)

```