
.. _options-protocol:

Protocol options
----------------

The following options have direct influence on SNMP engine operation.

SNMP version
++++++++++++

The *-v* option specifies SNMP version to be used:

* *1*  - SNMP version 1
* *2c* - SNMP version 2c
* *3*  - SNMP version 3

SNMP community
++++++++++++++

The *-c* option sets SNMP v1/v2c community name. It serves like a shared secret and
identification token between SNMP parties.

.. note::

   The community name is never encrypted on the wire so it's highly insecure.
   This is the sole reason why SNMP is sometimes jokingly referred to as
   *Security -- Not My Problem*.

SNMPv3 USM security name
++++++++++++++++++++++++

The *-u* option sets SNMP user name to the User Security Module subsystem. This
is a string from 1 to 32 octets of length. Should be configured in the same way
at both SNMP entities trying to communicate.

SNMPv3 USM security level
+++++++++++++++++++++++++

The *-l* option configures authentication and encryption features to be
used. In SNMP parlance this is known as *Security Level*. Valid values are:

* *noAuthNoPriv*   - no authentication and no encryption
* *authNoPriv*     - use authentication but no encryption
* *authPriv*       - use both authentication and encryption

SNMPv3 authentication protocol
++++++++++++++++++++++++++++++

SNMPv3 messages can be authenticated. The following authentication protocols
can be chosen via the *-a* option:

+--------+----------------+-------------+
| *ID*   | *Algorithm*    | *Reference* |
+--------+----------------+-------------+
| NONE   | -              | RFC3414     |
+--------+----------------+-------------+
| MD5    | HMAC MD5       | RFC3414     |
+--------+----------------+-------------+
| SHA    | HMAC SHA-1 128 | RFC3414     |
+--------+----------------+-------------+
| SHA224 | HMAC SHA-2 224 | RFC7860     |
+--------+----------------+-------------+
| SHA256 | HMAC SHA-2 256 | RFC7860     |
+--------+----------------+-------------+
| SHA384 | HMAC SHA-2 384 | RFC7860     |
+--------+----------------+-------------+
| SHA512 | HMAC SHA-2 512 | RFC7860     |
+--------+----------------+-------------+

SNMPv3 authentication key
+++++++++++++++++++++++++

SNMPv3 message authentication involves a shared secret key known to both SNMP
parties engaged in message exchange. This secret authentication key (AKA
as passphrase) can be conveyed via the *-A* option.

.. note::

   SNMP authentication key must be at least eight octets long.

SNMPv3 encryption protocol
++++++++++++++++++++++++++

SNMPv3 messages can be encrypted (AKA as privacy). The following encryption
protocols can be chosen via the *-x* option:

+------------+------------------------+----------------------+
| *ID*       | *Algorithm*            | *Reference*          |
+------------+------------------------+----------------------+
| NONE       | -                      | RFC3414              |
+------------+------------------------+----------------------+
| DES        | DES                    | RFC3414              |
+------------+------------------------+----------------------+
| AES        | AES CFB 128            | RFC3826              |
+------------+------------------------+----------------------+
| AES192     | AES CFB 192            | RFC Draft            |
+------------+------------------------+----------------------+
| AES256     | AES CFB 256            | RFC Draft            |
+------------+------------------------+----------------------+
| AES192BLMT | AES CFB 192 Blumenthal | RFC Draft            |
+------------+------------------------+----------------------+
| AES256BLMT | AES CFB 256 Blumenthal | RFC Draft            |
+------------+------------------------+----------------------+
| 3DES       | Triple DES EDE         | RFC Draft            |
+------------+------------------------+----------------------+

SNMPv3 encryption key
+++++++++++++++++++++

SNMPv3 message encryption involves a shared secret key known to both SNMP
parties engaged in message exchange. This secret encryption key (AKA
as passphrase) can be conveyed via the *-A* option.

.. note::

   SNMP encryption (e.g. privacy)  key must be at least eight octets long.

SNMPv3 context engine ID
++++++++++++++++++++++++

The *-E* option sets the context engineID used for SNMPv3 REQUEST messages
scopedPdu, given as a hexadecimal string. If not specified, this will
default to the authoritative engineID.

SNMPv3 engine ID
++++++++++++++++

The *-e* option sets the authoritative (security) engineID used for SNMPv3
REQUEST messages, given as a hexadecimal string.  It is typically not
necessary to specify engine ID, as it will usually be discovered
automatically.

SNMPv3 context name
+++++++++++++++++++

The *-n* option sets the SNMPv3 context name to SNMPv3 REQUEST messages.
The default is the empty string. SNMP context name is used to address a
specific instance of SNMP managed objects behind a single SNMP agent.

SNMPv3 engine boots and time
++++++++++++++++++++++++++++

The *-Z* option sets SNMP engine boot counter and its timeline values to
SNMPv3 REQUEST message. These values are used for message authentication.
It is typically not necessary to specify this option, as these values will
usually be discovered automatically.
