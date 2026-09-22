# MySQL client 8.4.11 for Turtle x64

The Windows x64 build uses the matched MySQL 8.4.11 SDK in dep/windows/mysql-8.4.11-x64. Headers, libmysql.lib and libmysql.dll come from the same official archive. PROVENANCE.json records its URL and SHA-256. The existing 32-bit dependency selection is unchanged.

CMake copies these runtime files into build/mantech-playerbots/bin and installs them with the server:

- libmysql.dll
- libcrypto-3-x64.dll
- libssl-3-x64.dll

Deploy these three files together with the rebuilt mangosd.exe/realmd.exe. The core may also require its existing OpenSSL 1.1 runtime; those files remain separate and must not be removed. This updates the application's database client, not the database server or schemas.

Five Windows zlib includes previously depended on walking up from the old MySQL include directory. They now resolve zlib/zlib.h through the existing Windows dependency include root.

Validation: 20,000 parameter binds with the new client plateaued at 73,728 bytes of private-memory growth. 2,000 mixed-type save-like transactions and rollback passed using a session-private temporary InnoDB table in local Turtle dev; no persistent test table was created. The old 5.5 client also passed the bounded bind test with zero private growth, so this test does not establish that the old client caused production RAM growth.

Full-build and world startup results will be recorded after completion. Production was not changed. An extended comparable-population memory run is still required before claiming any RAM improvement.

Completed: full Release native-ManTechPlayerbots build passed. CTest has no registered tests; the explicit SDK/bind/transaction tests above passed. Dev world PID 2288 loaded libmysql 8.4.11 and OpenSSL 3.5.7 from the build directory, reached 500 bots, ran the observation interval, closed all database connections, and exited 0. One transaction deadlock entered the existing retry path. The test harness stdin needed closing after save completion to release the Windows CLI reader; no server kill was used. The rebuilt login executable launches. Both executables, PDBs and the three new client DLLs were copied and hash-verified to the local Turtle output. Normal runtime configs were preserved. Production and GitHub were not changed. Long-session RAM behavior remains unverified.
