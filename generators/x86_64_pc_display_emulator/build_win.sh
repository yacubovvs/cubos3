DIRECTORY=`dirname "$0"`
cd $DIRECTORY
cd ../../
# woring at gcc v9.0+
g++ outputs/x86_64_pc_display_emulator/cubos/main.cpp -w -lws2_32 -o outputs/x86_64_pc_display_emulator/cubos/cubos
