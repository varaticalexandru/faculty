

import threading

def something_todo(ceva_parametru):

    thread_name = threading.current_thread().name
    print(f"Cica a primit {thread_name}: {ceva_parametru}")


t1 = threading.Thread(target=something_todo, args=("sobolan", ))
t2 = threading.Thread(target=something_todo, args=("izoteric", ))

t1.start()
t2.start()

t1.join()
t2.join()

print("Job done")