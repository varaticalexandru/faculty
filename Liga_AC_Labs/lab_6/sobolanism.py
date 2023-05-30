def sobolan(ceva_parametru: str, alt_parametru=None, *args, **kvargs) -> None:
    """Asta e un sobolan ezoteric de rang inalt. Deal with it.

    :ceva_parametru: face ceva idk
    :alt_parametur: daca nu-i dai, asta e
    """

    print(f"Am primit {ceva_parametru}")

    if alt_parametru:
        print(alt_parametru)

    print("received args:")

    for a in args:
        print(a)

    for key, value in kvargs.items():
        print(f"Key: {key}, Value: {value}")


lista = ["gigi", "sobolan", "ezoteric"]

dict = {"ceva_parametru": "sobolan", "ezoteric": "de rang inalt"}

print(*lista)
print(*dict)
