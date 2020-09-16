cmake_minimum_required(VERSION 3.16)
project(code)

set(CMAKE_CXX_STANDARD 98)

add_executable(code
        main.cpp
        model/dna/DnaSequence.cpp model/dna/DnaSequence.h
        model/dna/InvalidDna.cpp model/dna/InvalidDna.h
        model/dna_data/meta_data.cpp model/dna_data/meta_data.h
        model/dna_data/data.cpp model/dna_data/data.h
        view/interface/cli.cpp view/interface/cli.h
        view/interface/icli.cpp view/interface/icli.h
        controller/commands_container.cpp controller/commands_container.h
        controller/controller.cpp controller/controller.h
        view/parser.cpp view/parser.h
        controller/commands/icommand.cpp controller/commands/icommand.h
        controller/commands/usecase/load.cpp controller/commands/usecase/load.h
        controller/commands/usecase/new.cpp controller/commands/usecase/new.h
        controller/commands/usecase/save.cpp controller/commands/usecase/save.h
        controller/read_write/DNAReader.cpp controller/read_write/DNAReader.h controller/read_write/DNAWriter.cpp controller/read_write/DNAWriter.h shared_ptr.cpp shared_ptr.h model/dna/iDnaSequence.h)