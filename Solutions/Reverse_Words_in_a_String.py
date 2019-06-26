def Reverse_Words_in_a_String(text):
	text_lst = text.split()
	text_lst.reverse()
	words=""
	for word in text_lst:
		words+=word+"a"
	print(words[:-1])

if __name__ == '__main__':
	text = str(input())
	Reverse_Words_in_a_String(text)