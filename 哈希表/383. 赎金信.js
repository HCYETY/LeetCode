����һ������� (ransom) �ַ�����һ����־(magazine)�ַ������жϵ�һ���ַ��� ransom �ܲ����ɵڶ����ַ��� magazines ������ַ����ɡ�������Թ��ɣ����� true �����򷵻� false��

(��Ŀ˵����Ϊ�˲���¶������ּ���Ҫ����־������������Ҫ����ĸ����ɵ�����������˼����־�ַ����е�ÿ���ַ�ֻ����������ַ�����ʹ��һ�Ρ�)


ʾ�� 1��
���룺ransomNote = "a", magazine = "b"
�����false

ʾ�� 2��
���룺ransomNote = "aa", magazine = "ab"
�����false

ʾ�� 3��
���룺ransomNote = "aa", magazine = "aab"
�����true

��ʾ��
����Լ��������ַ�����ֻ����Сд��ĸ��



/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    // ���ù�ϣ��
    let hash = {};
    //��¼�ַ���ȱ
    for(let i = 0; i < ransomNote.length; i++) {
        let value =  ransomNote[i];
        hash[value] ? hash[value]++ : hash[value] = 1;
    }
    //���ȱ
    for(let i = 0; i < magazine.length; i++) {
        let flag = magazine[i];
        if(hash[flag])
            hash[flag]--;
    }
    //���鿴��ϣ��
    for(let key in hash)
        //����п�ȱû�������򷵻�false
        if(hash[key])
            return false;
    return true;
};
