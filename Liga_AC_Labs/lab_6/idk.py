# receives a dict and *args
# returns a new dict with only the fields specified in the *args 
# if the field does not exist, use the default value "SOBOLAN!"

def foo(dict, *args):

    new_dict = {}

    for arg in (args):
        new_dict[arg] = dict.get(arg, "SOBOLAN!")

    return new_dict