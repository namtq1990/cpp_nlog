# NLOG for C++

NLog is a C++ library designed for powerful logging, inspired by the well-known Timber library for Android.

## Installation

For testing, install [gtest](https://github.com/google/googletest)

Build NLog
```bash
mkdir build && cd build
cmake ..
make
sudo make install
```
optional build: 
```
-DTEST=ON : Build and run test
```
```
-Dbuf_size=1024 : Default max size for each log
```

## Usage

TODO

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
