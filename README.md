# Modern CPP challenge
Challenges in this book: https://www.packtpub.com/gb/application-development/modern-c-challenge

Setup:
- Clone the repository: `git clone https://github.com/risteaandrei/fizzbuzz.git`
- Go to scripts folder: `cd scripts`
- Create docker image: `./create_image.sh`
- Build the project: `./build.sh`
- Run the tests: `./test.sh`



ncat -l -k -p 50505 | ./client
nc localhost 50505 <<< 5