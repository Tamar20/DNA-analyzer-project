cmake_minimum_required(VERSION 3.16)
project(code)

set(CMAKE_CXX_STANDARD 98)

add_executable(code
        main.cpp
        dna/DnaSequence.cpp dna/DnaSequence.h
        dna/InvalidDna.cpp dna/InvalidDna.h
        dna_data/meta_data.cpp dna_data/meta_data.h
        dna_data/data.cpp dna_data/data.h
        interface/cli.cpp interface/cli.h
        interface/icli.cpp interface/icli.h
        manager/commands_container.cpp manager/commands_container.h
        manager/manager.cpp manager/manager.h
        manager/parser.cpp manager/parser.h
        commands/icommand.cpp commands/icommand.h
        commands/usecase/load.cpp commands/usecase/load.h
        commands/usecase/new.cpp commands/usecase/new.h
        commands/usecase/save.cpp commands/usecase/save.h
        model/read_write/DNAReader.cpp model/read_write/DNAReader.h model/read_write/DNAWriter.cpp model/read_write/DNAWriter.h)