import os
import argparse

def get_args():
	parser=argparse.ArgumentParser(description="Gray code generator code")
	parser.add_argument('-n','--number',type=int,help="Max number of bits of gray code generated",default=2)
	args=parser.parse_args()
	return args

def gray_code_generator(n):
	if n==2:
		return ["0","1"]
	else:
		return ["0"+d for d in gray_code_generator(n-1)]+["1"+d for d in gray_code_generator(n-1)[::-1]]

def main():
	args=get_args()
	print gray_code_generator(args.number)

if __name__ == '__main__':
	main()