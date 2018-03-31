#!/bin/bash

set -e

sudo apt-get install ncurses-dev
sudo updatedb
locate ncurses.h