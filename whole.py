import os
from operator import itemgetter

path = r'C:\Users\risinha\Documents\my docs\Personal projects\SongWordCount'
counts = {}
for dir_entry in os.listdir(path): #Reas files from 
	File_List = []
	
	dir_entry_path = os.path.join(path, dir_entry)
	if os.path.isfile(dir_entry_path):
		with open(dir_entry_path, 'r') as my_file:
			all_line = my_file.readlines()
			for line in all_line:
				words = line.split()
				for word in words:
					lower_case_word = word.lower()
					if lower_case_word not in File_List:
						File_List.append(lower_case_word)
					else:
						continue
			
			for wordLyrics in File_List:	
				if  wordLyrics not in counts:
					counts[wordLyrics] = 1
				else:
					counts[wordLyrics] += 1
			

for key,values in sorted(counts.items(), key = itemgetter(1), reverse=True):
	print(key,values)