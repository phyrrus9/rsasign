=RSA Code Signature program=
----------------------------
Copyright © 2013 Ethan Laur (phyrrus9) [@phyrrus9] <phyrrus9@gmail.com>

=About=
-------
The RSA signature program is aimed at preventing piracy and ensuring all
code run on your device is safe. This will be implemented in the Private
Dev iPhone App Store for jailbroken devices. If you wish to use this
feature, please follow the instructions section.

=The Process=
-------------
The process of submitting apps to the store follows below:
1. Developer writes code for the application
2. Developer zips all code together
3. Developer encrypts zip with their private (RSA/keygen) key
   To encrypt, use RSA/encrypt
4. Developer Submits application to the store (email phyrrus9@gmail.com)
5. The store verifies that this code came from the developer (by comparing
   the signatures from previous submissions). If you wish to develop, you
   MUST use the same signature, we will reject any code with differing
   signatures.
6. We decrypt the code, and encrypt the main binary with our private key
7. We sign the code (with the sig.pri key) and create an installer
8. The user installs the code on their device.
9. When the user executes the application, it is signature checked, if
   the signatures match, it is decrypted and run. Please see instructions
   for more details.

=Instructions=
--------------
In order for the code to be secure, the developer MUST include the following
line of code (preferably at the start of the application).
   unlink("/tmp/code");
This will ensure that nobody can modify your application.
If you wish to have a trial application, simply add
   unlink("/Applications/<your path>/<your main binary>.sig");
to your code.

=About the keys=
----------------
Both the signature key and the execution keys are different than the ones
included in this repository, and will be hidden on the filesystem (or in
memory somewhere) and will be inaccessable to users. No worries.

=Donations=
-----------
You can keep them, it's free software.
