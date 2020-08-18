#include "dna.h"
#include <fstream>
#include <cstring>
#include <algorithm>

bool valid_input(const char* str) {
    bool flag = true;
    size_t len = strlen(str);

    for (size_t i = 0; i < len; i++) {
        if (!(str[i] == 'A' || str[i] == 'T' || str[i] == 'G' || str[i] == 'C')) {
            flag = false;
            break;
        }
    }
    return flag;
}

/*std::string read_file(const char* file_name)
{
	std::string tmp,line;
	std::ifstream myfile(file_name);
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			tmp.append(line);
		}
		return tmp;
	}
	else return 0; 
}

void write_to_file(const char* file_name,std::string str)
{
	std::ofstream myfile;
	myfile.open(file_name);
	myfile << str;
	myfile.close();
}*/


// complexity: O(n)
DnaSeq DnaSeq::slicing(size_t start,size_t end)
{
	char* str = get_seq();
	std::string tmp;
	for (size_t i=start;i<end;i++)
	{
		tmp+=str[i];
	}
	DnaSeq dna(tmp);
	return dna;
}

// complexity: O(n)
DnaSeq pairing(DnaSeq& dna)
{
	std::map<char,char>  pairs;
	pairs['A'] = 'T';
	pairs['T'] = 'A';
	pairs['C'] = 'G';
	pairs['G'] = 'C';
	size_t length = dna.len();
	char* str = dna.get_seq();
	char tmp[length+1];
	for (size_t i=0;i<length+1;i++)
	{
		tmp[i] = pairs[str[length-i-1]];
	}
	tmp[length+1] = '\0';
	return DnaSeq(tmp);
}

// complexity: O(n*2)
size_t DnaSeq::find(const DnaSeq& sub)
{
	size_t length = len();
	size_t sublength = sub.len();
	char* str = get_seq();
	char* subseq = sub.get_seq();
	for(size_t i = 0; i<length;i++)
	{
		if(str[i]==subseq[0])
		{
			size_t j = 0;
			for(;j<sublength;j++)
			{
				if(str[i+j]!=subseq[j])
				{
					break;
				}
			}
			if(j == sublength)
			{
				return i;
			}
		}
	}
	return -1;
}

// complexity: O(n*2)
size_t DnaSeq::count(const DnaSeq& sub)
{
	size_t count = 0;
	size_t length = len();
	size_t sublength = sub.len();
	char* str = get_seq();
	char* subseq = sub.get_seq();
	for(size_t i = 0; i<length;i++)
	{
		if(str[i]==subseq[0])
		{
			size_t j = 0;
			for(;j<sublength;j++)
			{
				if(str[i+j]!=subseq[j])
				{
					break;
				}
			}
			if(j == sublength)
			{
				count++;
			}
		}
	}
	return count;
}

std::vector<size_t> DnaSeq::find_all(const DnaSeq& sub)
{
	std::vector<size_t> indexes;
	size_t length = len();
	size_t sublength = sub.len();
	char* str = get_seq();
	char* subseq = sub.get_seq();
	for(size_t i = 0; i<length;i++)
	{
		if(str[i]==subseq[0])
		{
			size_t j = 0;
			for(;j<sublength;j++)
			{
				if(str[i+j]!=subseq[j])
				{
					break;
				}
			}
			if(j == sublength)
			{
				indexes.push_back(i);
			}
		}
	}
	return indexes;
}

std::vector<DnaSeq> DnaSeq::find_consensus_seq(DnaSeq dna)
{

	std::vector<DnaSeq> consensus;
	
	std::string start = "ATG";
	DnaSeq sta(start);
	std::vector<size_t> start_indexes = find_all(sta);
	std::vector<size_t> end_indexes;
	
	std::string end1 = "TAG";
	DnaSeq e1(end1);
	std::vector<size_t> vend1 = find_all(e1);
	std::string end2 = "TAA";
	DnaSeq e2(end2);
	std::vector<size_t> vend2 = find_all(e2);
	std::string end3 = "TGA";
	DnaSeq e3(end3);
	std::vector<size_t> vend3 = find_all(e3);
	
	end_indexes.insert(end_indexes.begin(),vend1.begin(),vend1.end());
	end_indexes.insert(end_indexes.end(),vend2.begin(),vend2.end());
	end_indexes.insert(end_indexes.end(),vend3.begin(),vend3.end());
	std::sort(end_indexes.begin(),end_indexes.end());
	
	DnaSeq d(end1);
	//consensus.push_back(dna);

	for(size_t i = 0; i < start_indexes.size();i++)
	{
		for(int j = 0;j < end_indexes.size();j++)
		{
			if(start_indexes[i] < end_indexes[j])
			{
				if(!((end_indexes[j] - start_indexes[i])%3))
				{
					//std::cout<<slicing(start_indexes[i],end_indexes[j]+3).get_seq()<<std::endl;
					//DnaSeq d(slicing(start_indexes[i],end_indexes[j]+3));
					//consensus.push_back(slicing(start_indexes[i],end_indexes[j]+3));
				}
			}
		}
		
	}
	 /*for (int i = 0; i< consensus.size(); i++)
        	std::cout<<(consensus[i]).get_seq()<<std::endl;
        */
	std::cout<<"beforreturn\n";
	return consensus;
}






