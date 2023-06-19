#!/usr/bin/env python3

import json, os, sys

import flask

# Simple test app which will list/cat files on the host.
app = flask.Flask(__name__)


@app.route('/', defaults={'path': ''})
@app.route('/<path:path>')
def get_dirpath(path):
    path = f"/{path}"
    if os.path.isdir(path):
        # List entries within directories:
        return json.dumps(sorted(os.listdir(path)), indent=4)
    elif os.path.isfile(path):
        # Return contents of files:
        with open(path, "r") as fin:
            return fin.read()
    else:
        # 404 if the path is a link or does not exist:
        flask.abort(404)


if __name__ == "__main__":
    print(f"sys.argv: {sys.argv}")
    if len(sys.argv) < 3:
        raise ValueError(f"USAGE: python3 {sys.argv[0]} HOSTNAME PORT_NUMBER")
    hostname = sys.argv[1]
    port = int(sys.argv[2])

    app.run(hostname, port)