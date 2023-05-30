from concurrent import futures
import threading, time

x = 0
lock = threading.Lock()


def syncronized(lock):
    def wrapped(func):
        def inner(*args, **kvargs):
        
           lock.acquire()
           val = func(*args, **kvargs)
           lock.release()
           return val

        return inner
    return wrapped


@syncronized(lock)
def inc_x():
    global x
    lock.acquire()
    # x += 1
    # lock.release()

def work():
    
    for x in range(100000):
        inc_x()




def looper():
    global x
    x = 0

    now = time.time()
    
    pool = futures.ThreadPoolExecutor(max_workers=3)

    for i in range(10):
        pool.submit(work)

    pool.shutdown(wait=True)

    print(f"Job done! x = {x} in {time.time() - now}")

for i in range(10):
    looper()







