# Welcome to COMPS!!

This is gonna rock.

## Pulling the repo

We use git-lfs to track large files in the repo. Install that on OSX like this:

    brew install git-lfs
    
or take a look at [their docs](https://git-lfs.github.com/).

Then run the ol' clone command:

    git clone git@github.com:CarletonScenes/Scene-Reconstruction.git

## Installing OpenCV for feature detection

On Mac OSX:
```bash
brew tap homebrew/science
brew install opencv3 --c++11 --with-cuda --with-contrib
brew ln opencv3 --overwrite --force
```

## Running feature_detect
In Python:
```bash
cd feature_detect
python detect_basic.py
```

In C++:
```bash
cd feature_detect
cmake .
make
./FDTest test.jpg
./FMTest test1.jpg test2.jpg
```

## TODO:
- Update this todo with proper build instructions
- Save intermediate results (images with features) in separate directory
- Demo that generates points from two images
- Generate stereolithography (or equivalent) file from point outputs that we can open with meshlab
- Write end-to-end script that runs our program, saves the output, and opens it in meshlab

## SOME MAGIC

    cd python
    sudo easy_install pip
    sudo pip install virtualenv
    virtualenv env
    source ./env/bin/activate
    pip install -r requirements.txt

    brew install opencv3 --c++11 --with-cuda --with-contrib
    brew ln opencv3 --overwrite --force
    cp /usr/local/lib/python2.7/site-packages/cv* env/lib/python2.7/site-packages
    

## If you're using fish, you have to activate the env differently
    
    . ./bin/activate.fish
    
    
## Pythonpath stuff (in fish)
    set -x PYTHONPATH /Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/site-packages/
