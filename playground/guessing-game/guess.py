from random import randint

secret = randint(1, 10)
guess = 0
count = 0

print('Guess the secret number between 1 and 10')

while guess != secret:
    guess = int(input())
    count += 1

    if guess == secret:
        print('You got it! Nice job.')
    elif abs(guess - secret) == 1:
        print('You are really close! Try again.')
    elif guess < secret:
        print('Too low. Try again.')
    else:
        print('Too high. Try again.')

print('It took you {0} time(s) to guess.'.format(count))