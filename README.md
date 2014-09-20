Flesch-Kincaid-readability-test
===============================

CS 122 - Flesch-Kincaid readability test

This program is supposed to a simple Flesch readability check from the file provided by the user.

Since it is a simplified readability test, several assumptions were made:

-Amount of syllables equals the amount of vowels ( except when vowels follow each other 'for example: sway' or when Words end in 'e' like 'there').
- Any word has at least one syllable
- A sentence is any sequence of characters ending in a period, colon, semicolon, question mark, or exclamation mark. 

The results were tested with:

https://readability-score.com/

and 

http://randomtextgenerator.com/

The results are currently about ~10 off from the most common score. Some syllables are still seem not to be pulled.
