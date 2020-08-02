# Philosophers

## Mandatory part
### 당신은 세 개의 프로그램을 작성해야 하지만, 기본 규칙은 같습니다.

- 많은 철학자들은 원탁에 둘러앉아서 "먹기, 생각하기, 자기" 셋 중 하나를 하고 있습니다.

- 그들은 먹는 동안에는 생각하거나 잘 수 없고, 자는 동안에는 먹거나 생각할 수 없으며, 당연히 생각하는 동안에는 먹거나 잘 수 없습니다.

- 철학자들은 큰 그릇에 담긴 스파게티가 중앙에 있는 원탁에 앉아있습니다.

- 테이블 위에는 포크들이 놓여 있습니다.

- 스파게티는 포크 하나로 나눠담고 먹기 어렵기 때문에 철학자들은 한 손에 하나씩 두 손으로 포크를 쥐고 먹는다고 가정합니다.

- 철학자들은 절대 굶주려서는 안됩니다.

- 모든 철학자들이 먹어야 합니다.

- 철학자들은 서로 말을 하지 않습니다.

- 철학자들은 다른 철학자가 언제 죽을지 알 수 없습니다.

- 철학자들은 식사를 마칠 때마다 포크를 떨어트리고 잠을 자기 시작할 것입니다.

- 철학자가 잠을 다 자고나면 생각하기 시작할 것입니다.

- 철학자가 죽으면 시뮬레이션이 멈춥니다.

- 모든 프로그램은 아래와 같은 옵션을 가져야 합니다.

`number_of_philosophers`: 철학자들의 인원수이자 포크의 개수

`time_to_die`: 밀리초(milisecond)단위로 철학자가 마지막 식사를 시작한 이후 혹은 시뮬레이션이 시작한 이후에 time_to_die 밀리초에 식사를 시작하지 않는다면 죽을 것이다.

`time_to_eat`: 밀리초 단위이자 철학자가 먹는데 필요한 시간이다. 이 시간동안 철학자는 두 개의 포크를 가지고 있어야 할 것이다.

`time_to_sleep`: 밀리초 단위이자 철학자가 자는데 소비하는 시간이다.

`number_of_times_each_philosopher_must_eat`: 이 옵션은 선택적인 것으로, 만약 모든 철학자들이 최소 number_of_times_each_philosopher_must_eat동안 먹는다면 시뮬레이션은 종료될 것이다. 만약 정해지지 않았으면 시뮬레이션은 오직 철학자가 죽어야만 중단될 것이다.

- 각각의 철학자들은 1에서 number_of_philosophers까지의 숫자를 부여받는다.

- 철학자 번호 1은 철학자 번호가 number_of_philosophers인 철학자 옆에 있다. 1과 number_of_philosophers를 제외한 다른 숫자 n을 가진 철학자는 철학자 n-1번과 철학자 n+1번 사이에 앉는다.

- 철학자의 지위 변화는 다음을 따라야만 한다. (X는 `철학자번호`와 `timestamp_in_ms-밀리초에서 현재 timestamp`로 대체된다.)
```
timestamp_in_ms X has taken a fork.
timestamp_in_ms X is eating.
timestamp_in_ms X is sleeping.
timestamp_in_ms X is thinking.
timestamp_in_ms X died.
```
- 출력된 철학자의 지위는 다른 철학자가 뺏거나 다른 철학자의 지위와 중복될 수 없다.

- 철학자의 죽음으로부터 그의 죽음이 출력되기까지 10ms를 넘어서는 안된다.

- 다시 한 번, 철학자들은 죽음을 피해야 한다.

|					|				|
|:-:				|:--:			|
|Program Name		|philo_one		|
|Turn in files		|philo_one/		|
|Makefile			|Yes			|
|Arguments			|number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, [number_of_times_each_philosopher_must_eat]|
|External functs.	|memset, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_datach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock|
|Libft authorized	|No				|
|Description		|philosopher with threads and mutex|
|					|				|

이 프로그램에서 공통되지 않은 규칙은 다음과 같다.
- 각각의 철학자 사이에 포크 하나. 즉 철학자들의 왼쪽과 오른쪽에 포크가 있어야 한다.
- 철학자들이 중복된 포크를 집게 하지 않으려면, 포크의 상태를 mutex로 보호해야 한다.
- 각각의 철학자들은 쓰레드(thread)가 되어야 한다.

|					|				|
|:-:				|:--:			|
|Program Name		|philo_two		|
|Turn in files		|philo_two/		|
|Makefile			|Yes			|
|Arguments			|number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, [number_of_times_each_philosopher_must_eat]|
|External functs.	|memset, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, sem_open, sem_close, sem_post, sem_wait, sem_unlink|
|Libft authorized	|No				|
|Description		|philosopher with threads and semaphore|
|					|				|

이 프로그램에서 공통되지 않은 규칙은 다음과 같다.
- 모든 포크는 테이블 중앙에 있다.
- 메모리에는 들어있지 않지만, 사용가능한 포크의 수는 semaphore로 표시된다.
- 각각의 철학자들은 쓰레드(thread)가 되어야 한다.

|					|				|
|:-:				|:--:			|
|Program Name		|philo_three	|
|Turn in files		|philo_three/	|
|Makefile			|Yes			|
|Arguments			|number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, [number_of_times_each_philosopher_must_eat]|
|External functs.	|memset, malloc, free, write, fork, kill, exit, pthread_create, pthread_detach, pthread_join, usleep, gettimeofday, waitpid, sem_open, sem_close, sem_post, sem_wait, sem_unlink|
|Libft authorized	|No				|
|Description		|philosopher with processes and semaphore|

이 프로그램에서 공통되지 않은 규칙은 다음과 같다.
- 모든 포크는 테이블 중앙에 있다.
- 메모리에는 들어있지 않지만, 사용가능한 포크의 수는 semaphore로 표시된다.
- 각각의 철학자들은 프로세스가 되어야 하고 메인 프로세스는 철학자가 되어서는 안된다.