What it is:

Babushka Encryption is an encrption program.
I has multiple layers of encryption 6 in total.
It also decrypts its own encryption.

How it works:

The main class is the Controller class it is responsiable for encrypting and decrypting.
A message is passed in the encrpt function as a unsigned char*.
The key file then used the layers provied in the file to encrpt the data.

"encrption_key.txt" format

########################################################################################################

num_babushkas:7              <<< This line has the numbers of babushkas/layers there is.

gold:gdmvvaefhr:?            <<< The following lines are the type of babushkas/layers.
yellow:mKk53cPbNS                There should the three types which are type of Babushka, id and key
green:zkb44An6E2:1               except for yellow it only has the type and ID.
red:0123456789:5                 There should be seperated by semi-colons.
lightblue:hQtMoazX5f:2
darkblue:W7CdNV2qIa:1
green:zkb44An6E2:1

########################################################################################################

NOTE:

The babushka/layers types are lightblue, darkblue, gold, green, red and yellow.
Each babushka/layers has a specific data type key.
Please follow the format strictly an example can be found in "encryption_key.txt"
