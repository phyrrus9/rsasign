=RSA Code Signature program=
----------------------------
Copyright © 2013 Ethan Laur (phyrrus9) [@phyrrus9] <phyrrus9@gmail.com>

=About=
-------
The RSA signature program is aimed at preventing piracy and ensuring all<br />
code run on your device is safe. This will be implemented in the Private<br />
Dev iPhone App Store for jailbroken devices. If you wish to use this<br />
feature, please follow the instructions section.<br />

=The Process=
-------------
The process of submitting apps to the store follows below:<br />
1. Developer writes code for the application<br />
2. Developer zips all code together<br />
3. Developer encrypts zip with their private (RSA/keygen) key<br />
   To encrypt, use RSA/encrypt<br />
4. Developer Submits application to the store (email phyrrus9@gmail.com)<br />
5. The store verifies that this code came from the developer (by comparing<br />
   the signatures from previous submissions). If you wish to develop, you<br />
   MUST use the same signature, we will reject any code with differing<br />
   signatures.<br />
6. We decrypt the code, and encrypt the main binary with our private key<br />
7. We sign the code (with the sig.pri key) and create an installer<br />
8. The user installs the code on their device.<br />
9. When the user executes the application, it is signature checked, if<br />
   the signatures match, it is decrypted and run. Please see instructions<br />
   for more details.

=Instructions=
--------------
In order for the code to be secure, the developer MUST include the following<br />
line of code (preferably at the start of the application).<br />
   unlink("/tmp/code");<br />
This will ensure that nobody can modify your application.<br />
If you wish to have a trial application, simply add<br />
   unlink("/Applications/<your path>/<your main binary>.sig");<br />
to your code.<br />

=About the keys=
----------------
Both the signature key and the execution keys are different than the ones<br />
included in this repository, and will be hidden on the filesystem (or in<br />
memory somewhere) and will be inaccessable to users. No worries.<br />

=Donations=
-----------
You can keep them, it's free software.<br />
