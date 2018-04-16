#! /bin/bash

echo -e "Hi, please type the word: \c"
read word
echo "the word u entered is: ${word}"

echo -e "Can u plz enter two words?"
read word1 word2
echo "Here is ur input: \"${word1}\" \"${word2}\""

echo -e "How do u feel about bash scripting ?"
read
echo "U said $REPLY, Im glad to hear that"

echo -e "What are ur favorite colours ?"
read -a colours
echo "My favorite colours are also ${colours[0]}, ${colours[1]} and ${colours[2]}:-)"
