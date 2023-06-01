from contextlib import contextmanager


@contextmanager
def my_fopen(filename, filemode):
    print(f"Opening file {filename} with mode {filemode}")

    f = open(filename, filemode)

    yield f

    print(f"Finished processing file ...")
    f.close()
