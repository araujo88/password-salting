# password-salting

Password salting example written in C utilizing hashing algorithm SHA-256 (SHA-2). Developed for educational purposes only. THIS ALGORITHM HAS NOT BEEN TESTED AND AUDITED, SO DON'T USE IT ON A REAL APPLICATION!

## Compiling

`$ make clean` <br />
`$ make` <br />

## Usage

`$ ./password-salting <password> <work_factor> <salt_size>`

## Example

`$ ./password-salting password1234 16 8`

### Output

`Password: password1234` <br />
`Work factor: 16` <br />
`Number of iterations: 65536` <br />
`Salt length: 8` <br />
`Generated salt: 3425e872` <br />
`Salted password: password12343425e872` <br />
`Final hashed salted password: 7ce5aec45f2ead6e6c28ab7a88be6d3a73f359be8f535facedc94d110138d8d7` <br />

## Algorithm

1. The program reads an specified string which will be the password to be salted and hashed, the work factor and the salt size in bytes;
2. A random salt is generated using /dev/urandom with the given input length;
3. The salt is appended to the given string (password);
4. The hashing algorithm SHA256 is applied N times, which is given by 2^work_factor:
   SHA256(SHA256(SHA256(SHA256...SHA256(password+salt)...)))
5. Finally, the program outputs the final hashed salted password.
