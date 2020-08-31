# Copyright 2017-2020 Siemens AG
# 
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including without
# limitation the rights to use, copy, modify, merge, publish, distribute,
# sublicense, and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
# SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
# OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
# ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.
# 
# Author(s): Thomas Riedmaier

use strict;
use warnings;

open(my $file, ">", "_stricmp.cpp") or die "Could not open out file ";

print $file "#include \"stdafx.h\"\n";
print $file "#include \"fuzzcmp.h\"\n";
print $file "#include \"strcmpi.h\"\n";
print $file "#include \"_stricmp.h\"\n";



print $file "\nint __cdecl my_stricmp_(size_t caller, const char * str1, const char * str2){\n";
print $file "return mystrcmpi_(caller, str1, str2);\n";
print $file "}\n";

close $file

