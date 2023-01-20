#!/usr/bin/expect -f

spawn scp ./src/cat/s21_cat ./src/grep/s21_grep student@192.168.100.10:/home/student/

expect {
    "*yes/no" { send -- "yes\r" }
    "*password" { send -- "student\r" }    
}

expect {
    "*yes/no" { send -- "yes\r" }
    "*password" { send -- "student\r" }    
}

spawn ssh student@192.168.100.10 "echo student | sudo -S mv s21_cat s21_grep /usr/local/bin/"

expect "*password*"
send -- "student\r"

expect eof

