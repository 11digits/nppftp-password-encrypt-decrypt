char* SU::DataToHex(const char * data_, int len) {
	static const char * table = "0123456789ABCDEF";

	const unsigned char * data = (unsigned char*)data_;

	if (len == -1)
		len = strlen(data_);

	char * hexString = new char[len*2+1];
	for(int i = 0; i < len; i++) {
		unsigned int curVal = (unsigned int)data[i];
		hexString[i*2] = table[curVal/16];
		hexString[i*2+1] = table[curVal%16];
	}
	hexString[len*2] = 0;

	return hexString;
}

char* SU::HexToData(const char * hex, int len, bool addZero) {
  if (len == -1)
    len = strlen(hex);

  if (len%2 != 0)
    return NULL;

  len = len/2;
  unsigned char * data = new unsigned char[len + (addZero?1:0)];

  for(int i = 0; i < len; i++) {
    data[i] = 0;

    if (hex[i*2] <= '9')
      data[i] += (hex[i*2] - '0') * 16;
    else
      data[i] += ((hex[i*2] - 'A') + 10) * 16;

    if (hex[i*2+1] <= '9')
      data[i] += (hex[i*2+1] - '0');
    else
      data[i] += (hex[i*2+1] - 'A') + 10;
  }

  if (addZero) {
    data[len] = 0;
  }

  return (char*)data;
}


int SU::FreeChar(char * string) {
  if (!string)
    return -1;

  delete [] string;
  return 0;
}
