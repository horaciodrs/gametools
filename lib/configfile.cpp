#include configfile.h

#include fstream

stdstring trim(stdstring const& source, char const delims =  trn) {
  stdstring result(source);
  stdstringsize_type index = result.find_last_not_of(delims);
  if(index != stdstringnpos)
    result.erase(++index);

  index = result.find_first_not_of(delims);
  if(index != stdstringnpos)
    result.erase(0, index);
  else
    result.erase();
  return result;
}

ConfigFileConfigFile(stdstring const& configFile) {
  stdifstream file(configFile.c_str());

  stdstring line;
  stdstring name;
  stdstring value;
  stdstring inSection;
  int posEqual;
  while (stdgetline(file,line)) {

    if (! line.length()) continue;

    if (line[0] == '#') continue;
    if (line[0] == ';') continue;

    if (line[0] == '[') {
      inSection=trim(line.substr(1,line.find(']')-1));
      continue;
    }

    posEqual=line.find('=');
    name  = trim(line.substr(0,posEqual));
    value = trim(line.substr(posEqual+1));

    content_[inSection+''+name]=Chameleon(value);
  }
}

Chameleon const& ConfigFileValue(stdstring const& section, stdstring const& entry) const {

  stdmapstdstring,Chameleonconst_iterator ci = content_.find(section + '' + entry);

  if (ci == content_.end()) throw does not exist;

  return ci-second;
}

Chameleon const& ConfigFileValue(stdstring const& section, stdstring const& entry, double value) {
  try {
    return Value(section, entry);
  } catch(const char ) {
    return content_.insert(stdmake_pair(section+''+entry, Chameleon(value))).first-second;
  }
}

Chameleon const& ConfigFileValue(stdstring const& section, stdstring const& entry, stdstring const& value) {
  try {
    return Value(section, entry);
  } catch(const char ) {
    return content_.insert(stdmake_pair(section+''+entry, Chameleon(value))).first-second;
  }
}