



pipeline {
    agent any
    
    stages {
        stage('checkout') {
            steps {
                checkout scmGit(branches: [[name: '*/main']], extensions: [], userRemoteConfigs: [[credentialsId: 'jenkinstoken', url: 'https://github.com/GogirlDipika/CProgramTest.git']])
            }
        }
        
        stage('clone') {
            steps {
                git branch: 'main', credentialsId: 'jenkinstoken', url: 'https://github.com/GogirlDipika/CProgramTest.git'
            }
        }
        stage('Compile') {
            steps {
                bat 'gcc -o Sonarproject.exe Sonarproject.c'
            }
        }
        stage('Test') {
            steps {
                bat 'Sonarproject.exe'
            }
        }
        stage('Cppcheck') {
            steps {
                bat 'cppcheck --platform=win64 --inconclusive --enable=all --xml . 2> cppcheck.xml'
            }
        }
    }
}

       



