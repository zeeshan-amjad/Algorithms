def exact_root (bignumber):
	q = 0  #quotient
	d = 0  #dividend 

	numbits = bignumber.bit_length()
	numbits += numbits % 2    #round upto next even number

	for i in xrange (numbits, -1, -1):
		curbits = (bignumber >> (2 * i)) & 0b11
		if ((d - q*q) << 2) + curbits >= (q << 2) + 1:
			q = (q << 1) + 1
		else:
			q = q << 1

		d = (d << 2) + curbits

	return (q, d - q*q)
