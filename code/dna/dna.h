#ifndef DNA_H
#define DNA_H
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>


bool valid_input(const char*);




class InvalidDna: public std::exception
{
public:
    const std::string what();
};

inline const std::string InvalidDna::what()
{
    return "You're DNA is invalid.\ncorrect DNA contain only the letters: A, T, C or G.\ntry again.";
}




class DnaSequence
{

private:
	class Nucleotid
	{
	public:
	    Nucleotid(const char);
	    char getChar()const;
	    Nucleotid& operator= (const char);
	    
	private:
	    char m_nuc;
	};
     char* m_seq;
     
public:
    DnaSequence(char *seq);
    DnaSequence(std::string& seq);
    ~DnaSequence();
    DnaSequence(const DnaSequence &dna);
    DnaSequence& operator = (const DnaSequence &dna);
    bool operator == (const DnaSequence &dna)const;
    bool operator != (const DnaSequence &dna)const;
    char& operator[](size_t index)const;
    DnaSequence::Nucleotid& operator[](size_t index);
    size_t len()const;
    char* get_seq()const;
    
    DnaSequence slicing(size_t,size_t);
    size_t find(const DnaSequence&);
    size_t count(const DnaSequence&);
    std::vector<size_t> find_all(const DnaSequence&);
    std::vector<DnaSequence> find_consensus_seq(DnaSequence);
	
};


bool is_nuc(const char c);

inline bool is_nuc(const char c)
{
    return (c=='A' || c=='T'||c=='G'||c=='C');
}

inline char DnaSequence::Nucleotid::getChar()const
{
    return m_nuc;
}


inline DnaSequence::Nucleotid::Nucleotid(const char nuc):m_nuc(nuc) {
    if(!is_nuc(nuc))
        throw InvalidDna();
}

inline DnaSequence::Nucleotid& DnaSequence::Nucleotid::operator= (const char c){
    if(!is_nuc(c))
        throw InvalidDna();
    m_nuc=c;
    return *this;
}


inline DnaSequence::DnaSequence(char *dna)
{
    try{
        if (dna==NULL)
            throw InvalidDna();

        if(!valid_input(dna))
            throw InvalidDna();
    }
    catch (InvalidDna& e)
    {
        std::cout << e.what();
        throw;
    }
    m_seq = new char[strlen(dna)];
    strcpy(m_seq, dna);
}

inline DnaSequence::DnaSequence(std::string& dna)
{
    try{
        if (dna.c_str()==NULL)
            throw InvalidDna();

        if(!valid_input(dna.c_str()))
            throw InvalidDna();
    }
    catch (InvalidDna& e) {
        std::cout << e.what();
        throw;
    }
    m_seq = new char[dna.length() + 1];
    strcpy(m_seq, dna.c_str());
}

inline DnaSequence::DnaSequence(const DnaSequence& dna){
        char *tmp=m_seq;
        m_seq = new char[strlen(dna.get_seq()) + 1];
        strcpy(m_seq, dna.get_seq());
        delete[] tmp;
        tmp=NULL;
}

inline DnaSequence::~DnaSequence()
{
	//std::cout<<"before_d\n";
    delete [] m_seq;
    m_seq = NULL;
    //std::cout<<"after_d\n";
}

inline DnaSequence& DnaSequence::operator = (const DnaSequence &dna)
{
    if(this != &dna)
    {
        char *tmp=m_seq;
        m_seq = new char[strlen(dna.get_seq()) + 1];
        strcpy(m_seq, dna.get_seq());
        delete[] tmp;
        tmp=NULL;
    }
    return *this;
}

inline bool DnaSequence::operator == (const DnaSequence &dna)const
{
    return strcmp(m_seq,dna.get_seq())==0;
}

inline bool DnaSequence::operator != (const DnaSequence &dna)const
{
    return strcmp(m_seq,dna.get_seq())!=0;
}

inline char& DnaSequence::operator[](size_t index)const
{
    return m_seq[index];
}

inline DnaSequence::Nucleotid& DnaSequence::operator[](size_t index)
{
    Nucleotid* nuc =new Nucleotid(m_seq[index]);
    return *nuc;
}

inline size_t DnaSequence::len()const
{
    return strlen(m_seq);
}

inline char* DnaSequence::get_seq()const
{
    return m_seq;
}

inline std::ostream& operator << (std::ostream& os, const DnaSequence &dna)
{
    os<< dna.get_seq() << "\n";
    return os;
}




std::string read_file(const char*);
void write_to_file(const char*,std::string);
DnaSequence pairing(DnaSequence&);


#endif //DNA_H

