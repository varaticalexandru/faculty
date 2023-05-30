class JojoException(Exception):
    pass



def logger(func):
    def inner(*args, **kvargs):
        print("Function {func.__name} received args: {args}, {kvargs}")

        return func(*args, **kvargs)
    return inner


def exc_wrapper(exc_type):
    def wrapped(func):
        def inner(*args, **kvargs):
        
            try:
                import pdb; pdb.set_trace()
                return func(*args, **kvargs)
            except:
                print("You expected an exception, but it was I, DIO!")
                return None

        return inner
    return wrapped




@exc_wrapper(JojoException)
@logger
def sobolan(a, b, c):
    raise JojoException("Gigi")

sobolan(40, 30, c="gigi")