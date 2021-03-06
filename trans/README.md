# DRA TDF Installers

trans contains the compiler code generation back-ends, which translate
the compiler intermediate form, TDF, to the appropriate machine instructions.
In TDF's terminology this process is known as "installing" TDF.

## Structure

The src directory is split into a common section, containing code
which is used by all the back ends, plus a directory for each of the
target CPUs:

    alpha       DEC Alpha,
    hppa        HP Precision Architecture,
    m68k        Motorola 68020, 68030 and 68040,
    mips        SGI/DEC MIPS,
    power       POWER and POWER PC,
    sparc       SPARC.
    x86         Intel i386, i486 and Pentium,

The common installer directory is subdivided, for convenience, into
a number of different subdirectories:

    construct   routines and datatypes for the internal representation;

    diag
    newdiag     routines for reading and processing diagnostic information
                contained within the TDF;

    dwarf
    dwarf2      routines for writing out diagnostic information
                as DWARF and DWARF 2 directives;

    linkinfo    which contains routines for reading linkage
                information contained within the TDF;

    main        the main program interface and argument processing;

    reader      which contains the main routine for reading the
                input TDF and building up the internal representation;

    refactor    routines for optimising the internal representation;

    symtab      representation of the Third Eye binary symbol table format;

    templ       template files used to generate the TDF reading routines;

    utility     things that didn't fit anywhere else.

